class Singer:
    singers = []
    def _init_(self, name, song_type, country) -> None:
        self.name = name
        self.song_type = song_type
        self.country = country
        Singer.singers.append(self)

class Album:
    albums = []
    def _init_(self, album_name, singer_name, year) -> None:
        self.album_name = album_name
        self.year = year
        self.singer_name = singer_name
        Album.albums.append(self)

while True:
    print("""
1) Create an album
2) Create a singer
3) List singers
4) List albums    
    """)
    choice = input('What would you like to do: ')

    if choice == '1':
        album_name = input('Enter album name: ')
        year = input('Enter album year: ')

        for index, singer in enumerate(Singer.singers):
            print(f'{index + 1}. Singer: {singer.name}, country: {singer.country}, type: {singer.song_type}')

        singer = input('Choose a singer for this album [enter a number]: ')
        album = Album(album_name, Singer.singers[int(singer) - 1].name, year)
    elif choice == '2':
        name = input('Enter singer name: ')
        song_type = input('Enter music type: ')
        country = input('Enter country: ')

        singer = Singer(name, song_type, country)
    elif choice == '3':
        for index, singer in enumerate(Singer.singers):
            print(f'{index + 1}. Singer: {singer.name}, country: {singer.country}, type: {singer.song_type}')
    elif choice == '4':
        for index, album in enumerate(Album.albums):
            print(f'{index + 1}. Album: {album.album_name}, year: {album.year}, singer: {album.singer_name}')
    else:
        break