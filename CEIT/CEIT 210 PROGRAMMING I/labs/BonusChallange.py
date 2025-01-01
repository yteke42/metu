import random
import json

EMPTY = 'e'
TREASURE = 't'
MONSTER = 'm'
SWORD = 's'
POTION ='p'
VENOM = "v"
NOTDISPLAY = " "

countPoints = 0

whatToAddInGrid = (TREASURE, TREASURE, TREASURE, TREASURE, TREASURE,
MONSTER, MONSTER, MONSTER, MONSTER, MONSTER,
SWORD, SWORD,
POTION, POTION, POTION,
VENOM, VENOM, VENOM)

NROWS_IN_GRID = 6
NCOLS_IN_GRID = 7

grid = []

gridEmpty = []


for r in range(0, NROWS_IN_GRID): #0-6
  aRow = []
  aRowEmpty = []
  for c in range(0, NCOLS_IN_GRID):#0-7
    aRow.append(EMPTY)  
    aRowEmpty.append(" ")
  grid.append(aRow)
  gridEmpty.append(aRowEmpty)


print()
print()




def findEmptyCell(grid, nRows, nCols):
  #Find a random starting cell that is empty.
  while True:
    row = random.randrange(nRows)
    col = random.randrange(nCols)
    if(grid[row][col] == EMPTY):
      return row, col

for item in whatToAddInGrid:
  rowRandom, colRandom = findEmptyCell(grid, NROWS_IN_GRID, NCOLS_IN_GRID)
  grid[rowRandom][colRandom] = item



#Setting the starting cell
startRow, startCol = findEmptyCell(grid, NROWS_IN_GRID, NCOLS_IN_GRID)
print('Starting at row:', startRow, 'col:', startCol)
score = 0
hasSword = 0
hasPotion = 0
visited_cells = set()

gridEmpty[startRow][startCol] = EMPTY
for row in gridEmpty:
  print(row)


while True:
  #move the user around
  direction = input('Press L, U, R, D to move: ').lower()
  print()

  if(direction == 'l'):
    if(startCol == 0):
      startCol = NCOLS_IN_GRID - 1
    else:
      startCol -= 1
  elif (direction == 'r'):
    if(startCol == NCOLS_IN_GRID - 1):
      startCol = 0
    else:
      startCol += 1      
  elif(direction == 'u'):
    if(startRow == 0):
      startRow = NROWS_IN_GRID - 1
    else:
      startRow -= 1
  elif(direction == 'd'):
    if(startRow == NROWS_IN_GRID - 1):
      startRow = 0
    else:
      startRow += 1  
  else:
    print('Invalid move. Quitting the game.')
    break

  foundInCell = grid[startRow][startCol]
  print('Now at row', startRow, ' col:', startCol, ' cell contains:', foundInCell)

  gridEmpty[startRow][startCol] = foundInCell

  for row in gridEmpty:
      print(row)


  if (startRow, startCol) in visited_cells:
    print('You have already visited this cell')
    continue

  visited_cells.add((startRow, startCol))


  if foundInCell == "e":
    print("The cell is empty.")
    score += 1
  elif foundInCell == "t":
    score += 2
    print("You have found a treasure!!!")
    print("Your score is: ",score)
    grid[startRow][startCol] = EMPTY
    with open('gamelog.json', 'w') as f:
      json.dump({'score': score, 'swords': hasSword, 'potions': hasPotion}, f)

  elif foundInCell == "m":
    if hasSword > 0:
      print("You have run into a monster!!!")
      print("You have used your sword to kill the monster. Now, you don't have a sword.")
      hasSword -= 1
      grid[startRow][startCol] = EMPTY
      print("You have", hasSword,"swords left.")

      with open('gamelog.json', 'r') as f:
        data = json.load(f)
        print(data)

    elif hasSword == 0:
      print("You have run into a monster!!!")
      print("You don't have any sword to kill the monster. You died.")
      print("Your score is", score)
     
      with open('gamelog.json', 'w') as f:
        json.dump({'score': score, 'swords': hasSword, 'potions': hasPotion}, f)
      break
  elif foundInCell == "p":
      print("You have found a potion.")
      hasPotion += 1
      grid[startRow][startCol] = EMPTY
      with open('gamelog.json', 'w') as f:
        data = json.dump({'score': score, 'swords': hasSword, 'potions': hasPotion}, f)


  elif foundInCell == "s":
      hasSword += 1
      grid[startRow][startCol] = EMPTY
      print("You have found a sword.")
      with open('gamelog.json', 'w') as f:
        json.dump({'score': score, 'swords': hasSword, 'potions': hasPotion}, f)


  elif foundInCell == "v":
    if hasPotion > 0:
      print("You have run into a venom!!!")
      print("You have used your potion to recover from the venom. Now, you don't have a potion.")
      hasPotion -= 1
      grid[startRow][startCol] = EMPTY
      with open('gamelog.json', 'w') as f:
        data = json.dump({'score': score, 'swords': hasSword, 'potions': hasPotion}, f)

    else:
      print("You have run into a venom!!!")
      print("You don't have any portion to recover from the venom. You died.")
      with open('gamelog.json', 'r') as f:
        data = json.load(f)
        print(data)
      break

