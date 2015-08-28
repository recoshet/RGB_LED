wifi.setmode(wifi.STATION)
wifi.sta.config("SSID","PASS")
print(wifi.sta.getip())

srv=net.createServer(net.TCP)
srv:listen(80,function(conn)
    conn:on("receive", function(client,request)
        local buf = "";
        local _, _, method, path, vars = string.find(request, "([A-Z]+) (.+)?(.+) HTTP");
        if(method == nil)then
            _, _, method, path = string.find(request, "([A-Z]+) (.+) HTTP");
        end
        local _GET = {}
        if (vars ~= nil)then
            for k, v in string.gmatch(vars, "(%w+)=(%w+)&*") do
                _GET[k] = v
            end
        end
        buf = buf.."<h1> ESP8266 Web Server</h1>";
        buf = buf.."<p>RED &nbsp;<a href=\"?pin=ON1\"><button>ON</button></a>&nbsp;<a href=\"?pin=OFF1\"><button>OFF</button></a></p>";
        buf = buf.."<p>GREEN <a href=\"?pin=ON2\"><button>ON</button></a>&nbsp;<a href=\"?pin=OFF2\"><button>OFF</button></a></p>";
        buf = buf.."<p>BLUE <a href=\"?pin=ON3\"><button>ON</button></a>&nbsp;<a href=\"?pin=OFF3\"><button>OFF</button></a></p>";
        buf = buf.."<p>Animation <a href=\"?pin=ANIMON\"><button>ON</button></a>&nbsp;<a href=\"?pin=ANIMOFF\"><button>OFF</button></a></p>";
        local _on,_off = "",""
        if(_GET.pin == "ON1")then
              print('R1');
        elseif(_GET.pin == "OFF1")then
              print('R0');
        elseif(_GET.pin == "ON2")then
              print('G1');
        elseif(_GET.pin == "OFF2")then
              print('G0');
        elseif(_GET.pin == "ON3")then
              print('B1');
        elseif(_GET.pin == "OFF3")then
              print('B0');
        elseif(_GET.pin == "ANIMON")then
              print('A1');
        elseif(_GET.pin == "ANIMOFF")then
              print('A0');
        end
        client:send(buf);
        client:close();
        collectgarbage();
    end)
end)