#!/bin/bash
date
whoami
hostname

echo "Процессор:"
echo -e -n "\t• Модель — "
lscpu|grep Имя  | awk '{print $3, $4, $5}'
echo -e -n "\t• Архитектура — "
lscpu|grep Архитектура| awk '{print $NF}'
echo -e -n "\t• Тактовая частота — "
lscpu|grep Имя| awk '{print $NF}' 
echo -e -n "\t• Количество ядер — "
lscpu|grep Ядер| awk '{print $NF}' 
echo -e -n "\t• Количество потоков на одно ядро — "
lscpu|grep Thread| awk '{print $NF}' 

echo  "Оперативная память:"
echo -e -n "\t• Всего — "
free -h | grep Память | awk '{print $2}'
echo -e -n "\t• Доступно — "
free | grep Память | awk '{print $7}'

echo  "Жесткий диск:"
echo -e -n "\t• Всего — "
df | grep "/$" | awk '{print $3}'
echo -e -n "\t• Доступно — "
df | grep "/$" | awk '{print $4}'
echo -e -n "\t• Смонтировано в корневую директорию — "
df | grep "/$" | awk '{print $1}'
echo -e -n "\t• SWAP всего — "
free | grep Подкачка | awk '{print $2}'
echo -e -n "\t• SWAP доступно — "
free | grep Подкачка | awk '{print $4}'

echo  "Сетевые интерфейсы:"
echo -e -n "\t• Количество сетевых интерфейсов — "
ls /sys/class/net | wc -l
echo
echo -e "Имя сетевого интерфейса\t\tMAC адрес\t\tIP адрес\t\tСкорость соединения"
for iface in /sys/class/net/*; do
	echo -ne "${iface##*/}\t\t\t\t";
	tr "\n" "\t" < "$iface/address";
	printf "%-24s" " $(ip -4 -o a | grep " ${iface##*/} " | tr -s ' ' |  cut -d ' ' -f4 | tr -d '\n')"; 
	ip -4 -0 a | grep " ${iface##*/}: " | tr -s ' ' | cut -d' ' -f13
done  
