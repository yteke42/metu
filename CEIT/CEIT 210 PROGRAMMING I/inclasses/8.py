from bs4 import BeautifulSoup
import requests
import pandas as pd


page = requests.get("https://realpython.github.io/fake-jobs/")

soup = BeautifulSoup(page.content, "html.parser")

media = soup.find_all(class_ = "card-content")

titles = []
locations = []
applyLinks = []


for card in media:
    titles.append(card.find(class_ = "title is-5").get_text().strip())
    locations.append(card.find(class_ = "location").get_text().strip())
    applyLinks.append(card.find_all(class_ = "card-footer-item")[1]['href'].strip())

result = pd.DataFrame({
    "Titles" : titles[:5],
    "Locations" : locations[:5],
    "Apply Links" : applyLinks[:5]
})
print(result)
