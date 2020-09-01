import requests
import requests
from bs4 import BeautifulSoup as BS
from prettytable import PrettyTable

i = 0
z = 1
y = 1

page = requests.get('https://coinmarketcap.com/')
html = BS(page.content, 'html.parser')
spam = 'cmc-table__cell cmc-table__cell--sticky cmc-table__cell--sortable cmc-table__cell--left cmc-table__cell--sort-by__'
spam2 = 'cmc-table__cell cmc-table__cell--sortable cmc-table__cell--right cmc-table__cell--sort-by__'
Name = html.find_all('td', class_= spam + "name")
Market_Cap = html.find_all('td', class_= spam2 + "market-cap")
Price = html.find_all('td', class_= spam2 + "price")
print("| Name | Market_Cap | Price |")
print("-----------------------------")
def function_search(search):
    global i, y, z
    while y != 1:
        i += 1
        if i == 100:
            print("ERROR")
            i = -1
            y = 1
        if Name[i].text == Search_n:
            print("| Name | Market_Cap | Price |")
            print("-----------------------------")
            print( '| ' + Name[i].text + ' | ' + Market_Cap[i].text + ' | ' + Price[i].text + ' |')
            i = -1
            y = 1
            print("Nayti eshe cto nibud? 1 - Yes/ 0 - No")
            z = int(input())

while i < 100:
    print( '| ' + Name[i].text + ' | ' + Market_Cap[i].text + ' | ' + Price[i].text + ' |')
    i += 1

while z != 0:
    i = -1
    y = 0
    print("Vvedite nazvanie: ")
    Search_n = input()
    function_search(Search_n)

