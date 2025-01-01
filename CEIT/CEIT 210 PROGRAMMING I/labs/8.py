from bs4 import BeautifulSoup
import requests
import pandas as pd

page = requests.get("https://www.imdb.com/chart/top/")

soup = BeautifulSoup(page.content, "html.parser")

media = soup.find(class_="lister-list").find_all("tr")

titles = []
years = []
ratings = []

for card in media:
    titles.append(card.find(class_ = "titleColumn").find("a").get_text().strip())
    years.append(card.find(class_ = "secondaryInfo").get_text().strip())
    ratings.append(card.find(class_ = "ratingColumn").get_text().strip())

result = pd.DataFrame({
    "Title" : titles,
    "Year" : years,
    "Rating" : ratings
})

print(result)

print("Average rating of all: ", result.Rating.astype("float").mean())
