from pymodbus.client.sync import ModbusTcpClient

client = ModbusTcpClient('192.168.1.104')
result = client.read_coil(1,1)
print result.bits[0]
client.close()
