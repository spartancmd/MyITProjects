import requests


r = requests.post("https://www.google.com")

# requests.post()
# requests.put()
# requests.delete()

print(r.status_code)
# print(r.content)
# print(r.text)
# print(r.headers)
# print(r.url)