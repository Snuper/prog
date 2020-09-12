#!/bin/bash
echo " Дата: $(date | awk '{print $2, $3, $4}')"
echo "Имя учетной записи: $(whoami)"
echo "Доменное имя учетной записи: $(hostname)"
echo "Процессор:"
echo " • Модель$(cat /proc/cpuinfo | grep "model name" | uniq | awk '{print $3, $4, $5, $6, $7, $8, $9}')"
echo " • Архитектура: $(uname -m)"
echo " • Частота: $(cat /proc/cpuinfo | grep "cpu MHz" | uniq | awk '{print $4}')"
echo " • Кол-во ядер: $(cat /proc/cpuinfo | grep "cpu cores" | uniq | awk '{print $4}')"
echo " • Кол-во потоков на одно ядро: $(cat /proc/cpuinfo | grep "siblings" | uniq | awk '{print $3}')"
echo "Оперативная память:"
echo " • Всего: $(cat /proc/meminfo | grep "MemTotal" | awk '{print $2, $3}')"
echo " • Доступно: $(cat /proc/meminfo | grep "MemFree" | awk '{print $2, $3}')"
echo  "Жесткий диск:"
echo -e -n "\t• Всего — "
df -h | grep "/$" | awk '{print $2}'
echo -e -n "\t• Доступно — "
df -h | grep "/$" | awk '{print $3}'
echo -e -n "\t• Смонтировано в корневую директорию — "
df -h | grep "/$" | awk '{print $1}'
echo -e -n "\t• SWAP всего — "
free -h | grep Подкачка | awk '{print $2}'
echo -e -n "\t• SWAP доступно — "
free -h | grep Подкачка | awk '{print $4}'
echo  "Сетевые интерфейсы:"
echo -e -n "\t• Количество сетевых интерфейсов: "
ls /sys/class/net | wc -l
echo
echo -e "Имя сетевого интерфейса\t\tMAC адрес\t\tIP адрес\t\tСкорость соединения"
for iface in /sys/class/net/*; do
	if [[ "lo" = "${iface##*/}" ]]; then
	echo "lo -"
else
	echo -ne "${iface##*/}\t\t\t\t";
	tr "\n" "\t" < "$iface/address";
	printf "%-24s" " $(ip -4 -o a | grep " ${iface##*/} " | tr -s ' ' |  cut -d ' ' -f4 | tr -d '\n')";
	echo " $(ip -4 -0 a | grep " ${iface##*/}: " | tr -s ' ' | cut -d' ' -f13) Mibit"
	fi
done