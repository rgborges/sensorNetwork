#Programa acessa o banco de dados
import MySQLdb #carrega módulo
con = MySQLdb.connect('localhost','monty','SENAI') #Conecta-se ao servidor
con.select_db('iot')                               #Seleciona o banco de dados
cursor = con.cursor()                              #é necessário um cursor
cursor.execute('SELECT * from iot.node') #faz um querry
# três maneiras para pegar o resultado
rs = cursor.fetchall() #pega todas as linhas
print(rs[0])
