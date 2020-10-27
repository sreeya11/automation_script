%% function def contract for ONE block
function newContract = generateContract(type,h,contract) %type,block in subsys,contract

%% get actual contract and subsID/name and inject it there
% sl = {'/'};
% for i = 1 : length(h)
%     name = get_param(h(i),'Name');
%     disp(name);
%     if strcmp(name, block)
%         type = get_param(h(i), 'BlockType');
        switch type
            case 'Gain'
                p = get_param(getfullname(h),'PortHandles');
                out = get_param(p.Outport,'Name');
                in = get_param(p.Inport, 'Name');
                gain_param = get_param(h,'Gain');
               
        
                newContract = strrep(strrep(strrep(contract, 'gain_constant', gain_param), 'output', out), 'input_signal', in);
                disp(newContract);
        
            case 'Sum'
                
                p = get_param(getfullname(h),'PortHandles');
                out = get_param(p.Outport,'Name');
                in1 = get_param(p.Inport(1), 'Name');
                in2= get_param(p.Inport(2), 'Name');
                sign = get_param(h, 'inputs');
               
                % add minus
                if contains(sign,'-')
                    newContract = strrep(strrep(strrep(strrep(contract, 'input_signal1', in2), 'input_signal2', in1), 'output', out),'+','-');
                else
                     newContract = strrep(strrep(strrep(strrep(strrep(contract, 'input_signal1', in1), 'input_signal2', in2), 'output', out),'input_signal3', '0'), 'input_signal4', '0') ;
                end
                    disp(newContract);
                
            
            case 'Product'
                
                p = get_param(getfullname(h),'PortHandles');
                out = get_param(p.Outport,'Name');
                in1 = get_param(p.Inport(1), 'Name');
                in2= get_param(p.Inport(2), 'Name');
                sign = get_param(h, 'inputs');
                if contains(sign,'/')
                    newContract = strrep(strrep(strrep(strrep(contract, 'input_signal1', in1), 'input_signal2', in2), 'output', out),'*','/');
                else
                    newContract = strrep(strrep(strrep(contract, 'input_signal1', in1), 'input_signal2', in2), 'output', out);
                end
                    disp(newContract);
            
            case 'Switch'
                
                p = get_param(getfullname(h),'PortHandles');
                disp(p);
                out = get_param(p.Outport,'Name');
                disp(out);
                in1 = get_param(p.Inport(1), 'Name');
                disp(in1);
                in2= get_param(p.Inport(2), 'Name');
                disp(in2);
                in3= get_param(p.Inport(3), 'Name');
                disp(in3);
                th = get_param(h,'threshold');
                newContract = strrep(strrep(strrep(strrep(strrep(contract, 'input_signal1', in1), 'input_signal2', in3), 'output', out), 'control_signal' , in2),'threshold', th);
                disp(newContract);
                
            case 'Saturate'
                p = get_param(getfullname(h),'PortHandles');
                out = get_param(p.Outport,'Name');
                in = get_param(p.Inport(1), 'Name');
                low = get_param(h, 'lowerlimit');
                %up = get_param(h, 'upperlimit');
                newContract = strrep(strrep(strrep(contract, 'input_signal', in), 'output', out), 'lower_limit' , low);
            
            case 'RelationalOperator'
                p = get_param(getfullname(h),'PortHandles');
                out = get_param(p.Outport,'Name');
                in1 = get_param(p.Inport(1), 'Name');
                in2 = get_param(p.Inport(2), 'Name');
                op = get_param(h, 'Operator');
                
                newContract = strrep(strrep(strrep(strrep(contract, 'input_signal1', in1), 'input_signal2', in2), 'output', out),'>',op );
            
            otherwise
                newContract = -1;
                
        end


end





