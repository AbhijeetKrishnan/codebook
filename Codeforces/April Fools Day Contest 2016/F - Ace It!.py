import urllib.request

seq = input()
url = "https://oeis.org/search?q=id:" + seq + "&fmt=text"

response = urllib.request.urlopen(url)
html = response.read()
s = html.decode("utf-8")

line_list = s.split('\n')
req_str = line_list[6]
req_str = req_str.split()
num_list = req_str[2].split(',')
print(num_list[0])
