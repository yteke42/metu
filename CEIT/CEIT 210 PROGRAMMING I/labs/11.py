class Team:
    league = "Champions League" #class atribute
    def __init__(self, id, name, wins, defeats, scoresAchieved, scoresConceded) -> None:
        self.id = id
        self.name = name
        self.wins = wins
        self.defeats = defeats
        self.scoresAchieved = scoresAchieved
        self.scoresConceded = scoresConceded
        self.average = self.scoresAchieved - self.scoresConceded
    def __str__(self) -> str: #TO MAKE IT SHOWN WHEN PRINTING IT
        return f"[{self.id}] {self.name}"

class FutballTeam(Team):
    def __init__(self, id, name, wins, defeats, scoresAchieved, scoresConceded, draws) -> None:
        self.draws = draws
        super().__init__(id, name, wins, defeats, scoresAchieved, scoresConceded)
    def __str__(self) -> str:
        return f"[{self.id}] {self.name}"
    def calculateMatchsPlayed(self):
        return self.wins + self.defeats + self.draws
    def calculatePoints(self):
        return (self.wins * 3) + self.draws
    def __str__(self) -> str:
        m = self.calculateMatchsPlayed()
        p = self.calculatePoints()
        return "FutballTeam" + super().__str__() + f"  | {m} matchs played, has {p} points."

class BasketballTeam(Team):
    def __init__(self, id, name, wins, defeats, scoresAchieved, scoresConceded, totalFauls, totalRebounds) -> None:
        self.totalFauls = totalFauls
        self.totalRebounds = totalRebounds        
        super().__init__(id, name, wins, defeats, scoresAchieved, scoresConceded)
    def __str__(self) -> str:
        return f"[{self.id}] {self.name}"
    def calculateMatchsPlayed(self):
        return self.wins + self.defeats
    def calculatePoints(self):
        return (self.wins * 2) + self.defeats
    def __str__(self) -> str:
        m = self.calculateMatchsPlayed()
        p = self.calculatePoints()
        return "BasketballTeam" + super().__str__() + f"  | {m} matchs played, has {p} points."

teamList = []
while True:
    print()
    print("\t 1) Add a team")
    print("\t 2) Display a single team")
    print("\t 3) List all teams")

    choice = input("What do you do?: ")
    if choice == "1":
        print()
        print("\t 1) Add a Futball Team")
        print("\t 2) Add a Basketball Team")
        choice2 = input("What type of team do you want to add? ")
        if choice2 == "1":
            try:
                id = int(input("Enter the id for the futball team: "))
                name = input("Enter the name for the futball team: ")
                wins = int(input("Enter the number of wins for the futball team: "))
                defeats = int(input("Enter the number of defeats for the futball team: "))
                scoresAchieved = int(input("Enter the number of scores achieved for the futball team: "))
                scoresConceded = int(input("Enter the number of scores conceded for the futball team: "))
                draws = int(input("Enter the number of draws for the futball team: "))
                id = FutballTeam(id, name, wins, defeats, scoresAchieved, scoresConceded, draws)
                teamList.append(id)
                print("The futball team has added.")
            except ValueError:
                print("You have to enter a value.")
                pass
        elif choice2 == "2":
            try:
                id = int(input("Enter the id for the basketball team: "))
                name = input("Enter the name for the basketball team: ")
                wins = int(input("Enter the number of wins for the basketball team: "))
                defeats = int(input("Enter the number of defeats for the basketball team: "))
                scoresAchieved = int(input("Enter the number of scores achieved for the basketball team: "))
                scoresConceded = int(input("Enter the number of scores conceded for the basketball team: "))
                totalFauls = int(input("Enter the number of fauls for the basketball team: "))
                totalRebounds = int(input("Enter the number of rebounds for the basketball team: "))
                id = BasketballTeam(id, name, wins, defeats, scoresAchieved, scoresConceded, totalFauls, totalRebounds)
                teamList.append(id)
                print("The basketball team has added.")
            except ValueError:
                print("You have to enter a value.")
                pass
    elif choice == '2':
        for team in teamList:
            print(f"[{team.id}] {team.name}")

        team_id = int(input("Which shape do you want to know properties of (Choose an id): "))
        for team in teamList:
            if team_id == team.id:
                print(team)
                break
    elif choice == "3":
        for team in teamList:
            print(f"[{team.id}] [{team.name}]")
    else:
        break
