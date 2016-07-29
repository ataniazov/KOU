id=0
sda=3 --GPIO0
scl=4 --GPIO2
i2c.setup(id, sda, scl, i2c.SLOW)

function read_reg(dev_addr, reg_addr) -- Read MCP9808 data
  i2c.start(id)
  i2c.address(id, dev_addr ,i2c.TRANSMITTER)
  i2c.write(id,reg_addr)
  i2c.stop(id)
  i2c.start(id)
  i2c.address(id, dev_addr,i2c.RECEIVER)
  c=i2c.read(id,2)
  i2c.stop(id)
  return c
end

function convert(tempval) -- convert 2 byte value
  t = tonumber(string.byte(tempval,1))
  t = bit.lshift(t,8) + tonumber(string.byte(tempval,2))
  temp = bit.band(t, 0x0FFF) / 16
   if t > 127 then t = t - 255 end
  return temp
end

function toFormat(ctemp)
  ftemp = ctemp
  return ftemp
end


function send_data(port, ip)
   sk=net.createConnection(net.TCP, 0)
   sk:connect(port, ip)
   sk:on("connection", function(sck,c)
        --tmr.alarm(0, 3000, tmr.ALARM_AUTO, function() sk:send(tostring(convert(read_reg(0x18, 0x05)))) end)
      tmr.alarm(0, 3000, tmr.ALARM_AUTO, function() sk:send("nodemcu to server test") end)
   end)
   if sk:close() == nil then
      node.restart()
   end
end

tmr.alarm(0, 1000, 1, function()
   if wifi.sta.getip() == nil then
      print("Connecting to AP...")
   else
      print('IP: ',wifi.sta.getip())
      send_data(8888, "192.168.223.76")
      tmr.stop(0)
   end
end)
