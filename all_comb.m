
copyfile('C:\Users\Diya\Documents\MATLAB\BBW\brake_acc_nodiv_ert_rtw\brake_acc_nodiv.c', 'C:\Users\Diya\Documents\MATLAB\BBW\brake_acc_nodiv_ert_rtw\brake_acc_nodiv-annotated.c');
%% get depth of the model
metric_engine = slmetric.Engine();
setAnalysisRoot(metric_engine,'Root','brake_acc_nodiv');%one param to overall func is model

res_col = getMetrics(metric_engine,{'mathworks.metrics.SubSystemDepth'}); %does not return statecharts
cnt = 1;
a=[];
for n=1:length(res_col)
    if res_col(n).Status == 0
        results = res_col(n).Results;
        
        for m=1:length(results)
            disp(['  Value: ',num2str(results(m).Value)]);
            a(cnt) = results(m).Value;
            cnt = cnt + 1;
        end
    end
end
depth = max(a);
disp(depth);


%% copy entire .c file to a new .c file
fid = fopen('C:\Users\Diya\Documents\MATLAB\BBW\brake_acc_nodiv_ert_rtw\brake_acc_nodiv.c');
cac = textscan( fid, '%s', 'Delimiter','\n', 'CollectOutput',true );
fclose(fid);

count = 1;

%% return subsystems at each level
for i = (depth):-1: 0 %skipped statcharts on level3 (2,1,0)
    m = giveSubsystemsatLevel(i);
    disp(m);
    %% for each depth level subsys, find lines and port signals and rename with ghosts etc
    for s = 1 : length(m) %m{s} is subsys at depth
        %all_blocks1 = find_system(m{s},'regexp','on','BlockType','Gain|Sum|Saturate|RelationalOperator|Switch|MinMax|Abs|UnitDelay|LogicalOperator|Product');
        sub_name = get_param(m{s}, 'Name');
        L = find_system(m{s},'regexp','on','FindAll','on','type','line');
        port = find_system(m{s}, 'regexp','on','BlockType', 'Inport|Outport');
        portNames = get_param(port, 'Name'); %this exp
        disp(portNames);
        for k=1 : length(L)
            Src=getfullname(get(L(k),'SrcBlockHandle'));
            disp(Src);
            Dst=getfullname(get(L(k),'DstBlockHandle'));
            disp(Dst);
            for i = 1 : length(portNames)
                if strcmp(portNames(i), 'v_km/h')
                    exp = 'v_km//h';
                    matchStr1 = regexp(Src, exp, 'match')  ;
                    disp(matchStr1);
                    matchStr2 = regexp(Dst, exp, 'match')  ;
                    disp(matchStr2);
                    matches_src = find(~cellfun('isempty', matchStr1)); %matches source or dest port
                    matches_dst = find(~cellfun('isempty', matchStr2)); % convert cell to reg variable
                    
                elseif strcmp(portNames(i), 'v: Vehicle Velocity (km/h)')
                    exp = '\w*sVelocity\s(km//h)';
                    matchStr1 = regexpi(Src, exp, 'match')  ;
                    disp(matchStr1);
                    matchStr2 = regexpi(Dst, exp, 'match')  ;
                    disp(matchStr2);
                    matches_src = find(~cellfun('isempty', matchStr1)); %matches source or dest port
                    matches_dst = find(~cellfun('isempty', matchStr2)); % convert cell to reg variable
                else
                    
                    matches_src = contains(Src, portNames(i));
                    matches_dst = contains(Dst, portNames(i));
                end
                
                
                if ismember(sub_name, {'ABS_RR_Wheel'}) & matches_src ~= 0
                    
                    disp(getfullname(L(k)));
                    pre = 'rtu_';
                    oldname = [portNames{i}]; %rtu_ and no space
                    if ismember(oldname, {'w_rpm'; 'w: wheel Rotation (rpm)'})
                        
                        newname = ['rtu_wwheelRotationrpm'];
                        disp(newname);
                        set_param(L(k),'Name', newname);% always handle
                        break;
                        
                    elseif ismember(oldname, {'T_Nm'; 'T: Requested Torque (Nm)'})
                        newname = ['rtu_TRequestedTorqueNm'];
                        disp(newname);
                        set_param(L(k),'Name', newname);% always handle
                        break;
                        
                    elseif ismember(oldname, {'v_km/h'; 'v: Vehicle Velocity (km/h)'})
                        newname = ['rtu_vVehicleVelocitykmh'];
                        disp(newname);
                        set_param(L(k),'Name', newname);% always handle
                        break;
                    end
                    
                    
                elseif ismember(sub_name, {'ABS_RR_Wheel'}) & (matches_dst ~= 0)
                    disp(getfullname(L(k)));
                    pre = 'rty_';
                    oldname = [portNames{i}]; %rtu_ and no space
                    
                    if ismember(oldname, {'BrakeTorque'; 'M_abs: Brake_Torque'})
                        newname = ['*rty_M_absBrake_Torque'];
                        disp(newname);
                        set_param(L(k),'Name', newname);% always handle
                        break;
                    end
                    
                elseif ismember(sub_name, {'RR_Wheel'}) & (matches_dst ~= 0)
                    disp(getfullname(L(k)));
                    pre = 'rty_';
                    oldname = [portNames{i}]; %rtu_ and no space
                    
                    if ismember(oldname, {'Wheel Speed (rpm)'})
                        newname = ['*rty_WheelSpeedrpm'];
                        disp(newname);
                        set_param(L(k),'Name', newname);% always handle
                        break;
                    end
                    
                elseif ismember(sub_name, {'FL_Wheel'}) & (matches_dst ~= 0) 
                    disp(getfullname(L(k)));
                    pre = 'rty_';
                    oldname = [portNames{i}]; %rtu_ and no space
                    
                    if ismember(oldname, {'Wheel Speed (rpm)'})
                        newname = ['*rty_WheelSpeedrpm'];
                        disp(newname);
                        set_param(L(k),'Name', newname);% always handle
                        break;
                    end
                    
                
                      
                    
                    
                elseif(matches_src ~= 0)
                    disp(getfullname(L(k)));
                    
                    newname = [portNames{i}]; %rtu_ and no space
                    
                    disp(newname);
                    set_param(L(k),'Name', newname);% always handle
                    
                    break;
                    
                    
                    
                elseif(matches_dst ~= 0)
                    disp(getfullname(L(k)));
                    
                    newname = [portNames{i}]; %rtu_ and no space
                    
                    disp(newname);
                    set_param(L(k),'Name', newname);% always handle
                    
                    break;
                    
                    
                    
               elseif (matches_src == 0) & (matches_dst == 0)
                    
                    newname1 = ['g_' num2str(k)];
                    if ismember(newname1, {'g_2'}) & ismember(sub_name, {'ABS_RR_Wheel'})
                        name = ['rtb_vms'];
                        set_param(L(k),'Name', name);
                    elseif ismember(newname1, {'g_25'}) & ismember(sub_name, {'ABS_RR_Wheel'})
                        name = ['rtu_vVehicleVelocitykmh'];
                        set_param(L(k),'Name', name);
                    elseif ismember(newname1, {'g_11'}) & ismember(sub_name, {'ABS_RR_Wheel'})
                        set_param(L(k),'Name', '0');

                    else
                        set_param(L(k),'Name', newname1);
                    end
                    
                    
            end
            
        end
        
        
        
        end
        
    end
end

for i = (depth):-1: 0 %skipped statcharts on level3
    m = giveSubsystemsatLevel(i);
    for s = 1 : length(m)
        
        %% after renaming signals, generate contract of that subsys
        %% find all atomic blocks within subsys
        
        all_blocks = find_system(m{s},'regexp','on','BlockType','Gain|Sum|Saturate|RelationalOperator|Switch|MinMax|Abs|UnitDelay|LogicalOperator|Product');
        out = find_system(m{s}, 'regexp','on','BlockType', 'Outport');
        a = get_param(out, 'PortConnectivity');
        sub_name = get_param(m{s}, 'Name');
        disp(sub_name);
        string = "static void" + " " + sub_name + '(';
        disp(string);
        for b = 1 : length(all_blocks)
            
            
            
            
            fid = fopen('contracts.txt');
            tline = fgetl(fid);
            block_name = get_param(all_blocks{b},'Name');
            disp(block_name);
            type = get_param(all_blocks{b}, 'BlockType');
            disp(type);
            %if strcmp(block_name, block)
            while ischar(tline) %comparing type with contract.txt
                if strfind(lower(tline),lower(type))
                    break;
                end
                tline = fgetl(fid);
            end
            contract = fgetl(fid);
            disp(contract);
            fclose(fid); % we get contract template
            
            %% search thru .h file and match line in h file with subsystem path and return subsys number (now .txt)
            fid = fopen('C:\Users\Diya\Documents\MATLAB\BBW\brake_acc_nodiv_ert_rtw\brake_acc_nodiv.h');
            tline = fgetl(fid);
            while ischar(tline)
                if contains(tline,m{s}) %string subs is a part of tline m{s} is subs
                    disp(tline);
                    break;
                end
                tline = fgetl(fid);
            end
            subsID = extractBetween(tline, "* '", "'  :");
            disp(subsID);
            
            fclose(fid);
            sl = {'/'};
            %% generate contract (no function post conditions as yet)
            if ismember(sub_name, {'Veh_Speed_Estimator'}) & ismember(type, 'Sum')
                    newContract = generateContract(type,all_blocks{b},contract);
                    p = get_param(getfullname(all_blocks{b}),'PortHandles');
                    in3 = get_param(p.Inport(3), 'Name');
                    in4= get_param(p.Inport(4), 'Name');
                    newContract = strcat(newContract, '+', in3, '+', in4);
            elseif ismember(sub_name, {'VehicleModel'}) & ismember(type, 'Saturate')
                newContract = generateContract(type,all_blocks{b},contract);
            elseif ismember(sub_name, {'VehicleModel'}) & ismember(type, 'Sum')
                 newContract = generateContract(type,all_blocks{b},contract);
            else
                newContract = generateContract(type,all_blocks{b},contract);
            end
            disp(newContract);
            if isequal(newContract, -1)
                continue; % skip abs, minmax, delay - todo
            end
            
            
            
            %% inject new contract in location (just ghosts)
%             
            blockid = strcat("'",subsID, sl, block_name,"'");
            if strcmp(block_name, 'v (m/s)')
                blockid = strcat("'",subsID, sl, 'v (m//s)',"'");
            elseif strcmp(block_name, 'wheSpd (m/s)')
                blockid = strcat("'",subsID, sl, 'wheSpd (m//s)',"'");
            elseif strcmp(block_name, 'u (grad/s)')
                blockid = strcat("'",subsID, sl, 'u (grad//s)',"'");
            
%          
            end
       
            disp(blockid);
            for i = 1:length(cac{1})
                
                if contains(cac{1}{i}, blockid)
                    line(count) = [i];
                    disp(line);
                   
                    
                    newestContract(count) = {['//@ghost' ' ' newContract]};
                    disp(newestContract);
                    count = count + 1;
                end
            end
       
        
        
       
            %% if output block, replace signal name to contract
            handle = get_param(all_blocks{b}, 'Handle');
            sub_name = get_param(m{s}, 'Name');
            if i == 0 & ismember(sub_name, {'ABS_RR_Wheel'; 'ABS_RL_Wheel';'ABS_FR_Wheel';'ABS_FL_Wheel'}) % top level
                if isequal(a{1}.SrcBlock, handle) | isequal(a{2}.SrcBlock, handle) %threshold, ABS_RR_Wheel
                    M = find_system(m{s},'BlockType','SubSystem');
                    l = get_param(M, 'LineHandles');
                    out = l{1}.Outport;
                    set_param(out, 'Name',newContract);
                end
                
            elseif ismember(sub_name, {'Veh_Speed_Estimator'})
                if isequal(a{1}.SrcBlock, handle)
                    M = find_system(m{s},'BlockType','SubSystem');
                    l = get_param(M, 'LineHandles');
                    out = l{1}.Outport;
                    set_param(out, 'Name',newContract);
                    disp(newContract);
                    j = newContract;
                    %break;
                end

                
                
            elseif ismember(sub_name, {'FL_Wheel'; 'FR_Wheel';'RL_Wheel';'RR_Wheel'})
                if isequal(a{1}.SrcBlock, handle) | isequal(a{2}.SrcBlock, handle)|isequal(a{3}.SrcBlock, handle) %for FL wheel etc
                    M = find_system(m{s},'BlockType','SubSystem');
                    l = get_param(M, 'LineHandles');
                    out = l{1}.Outport;
                    if ismember(newContract, '(g_2>0)?pout = g_4 : pout = g_1')
                        continue;
                    end
                    if ismember(newContract, '(g_149>0)?pout = g_151 : pout = g_148')
                        continue;
                    end
                    set_param(out(2), 'Name',newContract);
                    disp(get_param(out(2), 'Name'));
                    disp(newContract);
                    for h = 79:length(cac{1}) %skip static void inital declaration
                        if contains(cac{1}{h}, string)
                            line(count) = [h];
                            
                            
                            %newestContract(count) = {strcat('//@ ensures',newContract)};
                            newestContract(count) = {['//@ ensures' ' ' newContract]};
                            disp(newestContract);
                            count = count + 1;
                            break;
                        end
                        
                    end
                end
                
                
                
                
            elseif isequal(a{1}.SrcBlock, handle)
                M = find_system(m{s},'BlockType','SubSystem');
                l = get_param(M, 'LineHandles');
                out = l{1}.Outport;
                set_param(out, 'Name',newContract);
                if ismember(sub_name, {'VehicleModel'}) & ismember(type, 'Saturate')
                    j1 = newContract; %dont break
                    j2 = ' ';
                end
             elseif ismember(sub_name, {'VehicleModel'}) & ismember(type, 'Sum')
                    j2 = newContract;
                
            end
            
        
        
        
        
        
        
        end   
        
        %% inject post condition above function header (for subsys)
        sub_name = get_param(m{s}, 'Name');
        disp(sub_name);
        stringUpdate = "static void" + " " + sub_name + '_Update'+'(';
        %if ismember(sub_name, {'ABS_RR_Wheel'; 'FL_Wheel';'RR_Wheel'})
        if ismember(sub_name, {'ABS_RR_Wheel'; 'Veh_Speed_Estimator'; 'Vehicle_Body_Wheels'})
            string = "static void" + " " + sub_name + '(';
           
            disp(string);
            if ismember(sub_name, {'Vehicle_Body_Wheels'})
                newContract = strrep(newContract, 'g_201','*rty_Veh_Spd_Realkmh');
            end
            for i = 79:length(cac{1}) %skip static void inital declaration
                if contains(cac{1}{i}, string)
                    line(count) = [i];
                    disp(line);
                    
                    disp(newContract);
                    newestContract(count) = {['//@ ensures' ' ' newContract]};
                    disp(newestContract);
                    count = count + 1;
                end
            end
        elseif ismember(sub_name, {'VehicleModel'})
            string = "static void" + " " + sub_name + '(';
            stringUpdate = "static void" + " " + sub_name + '_Update'+'(';
            disp(string);
            disp(stringUpdate);
            for i = 79:length(cac{1}) %skip static void inital declaration
                if contains(cac{1}{i}, string) & ~isempty(j1)
                    line(count) = [i];
                    disp(line);
                    
                    disp(j1);
                    j1 = strrep(j1, 'g_201', '*rty_VehicleSpeedms');
                    disp(j1);
                    newestContract(count) = {['//@ ensures' ' ' j1]};
                    disp(newestContract);
                    count = count + 1;
                    
                elseif contains(cac{1}{i}, stringUpdate)& ~isempty(j2)
                    line(count) = [i];
                    disp(line);
                    
                    disp(j2);
                    j2 = strrep(j2, 'g_201', '*rty_VehicleSpeedms');
                    disp(j2);
                    newestContract(count) = {['//@ ensures' ' ' j2]};
                    disp(newestContract);
                    count = count + 1;
                end
            end
                    
                
                
        
                    
            
        
        end
        
    end
    end


fid = fopen( 'C:\Users\Diya\Documents\MATLAB\BBW\brake_acc_nodiv_ert_rtw\brake_acc_nodiv-annotated9.c', 'w' );
for jj = 1:length(cac{1})
    fprintf( fid, '%s\n', cac{1}{jj} );
    if (jj == 433) | (jj == 440)|(jj == 608)|(jj == 621) |(jj==681)|(jj==723)   
        continue;
    end
    for i = 1 : length(line)
        if isequal(jj,line(i)-1)
            if contains(newestContract{i}, {'ensures'})
                fprintf( fid, '%s\n', newestContract{i} );
            end
        
        elseif isequal(jj,line(i)) & contains(newestContract{i}, {'ghost'})
            fprintf( fid, '%s \n', newestContract{i} );
            disp(jj);

            
        end
    end
end

fclose( fid );
