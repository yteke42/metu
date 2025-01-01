import random

EMPTY = 'e'
TREASURE = 't'
MONSTER = 'm'
SWORD = 's'
POTION ='p'
VENOM = "v"

whatToAddInGrid = (TREASURE, TREASURE, TREASURE, TREASURE, TREASURE, MONSTER, MONSTER, MONSTER, MONSTER, MONSTER, SWORD, SWORD, SWORD, POTION, POTION, VENOM, VENOM, VENOM)


NROWS_IN_GRID = 6
NCOLS_IN_GRID = 8

grid = []

for r in range(0, NROWS_IN_GRID): #0-5
  aRow = []
  for c in range(0, NCOLS_IN_GRID):#0-7
    aRow.append(EMPTY)  
  grid.append(aRow)


def findEmptyCell(aGrid, nRows, nCols):
  #Find a random starting cell that is empty.
  while True:
    row = random.randrange(nRows)
    col = random.randrange(nCols)
    if(aGrid[row][col] == EMPTY):
      return row, col

for item in whatToAddInGrid:
  rowRandom, colRandom = findEmptyCell(grid, NROWS_IN_GRID, NCOLS_IN_GRID)
  grid[rowRandom][colRandom] = item

for row in grid:
  print(row)

#Setting the starting cell
startRow, startCol = findEmptyCell(grid, NROWS_IN_GRID, NCOLS_IN_GRID)
print('Starting at row:', startRow, 'col:', startCol)
score = 0
hasSword = False
hasPotion = False
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

  if foundInCell == "e":
    print("The cell is empty.")

  elif foundInCell == "t":
    score += 1
    print("You have found a treasure!!!")
    print("Your score is: ",score)
    grid[startRow][startCol] = EMPTY

  elif foundInCell == "m":
    if hasSword == True:
      print("You have run into a monster!!!")
      print("You have used your sword to kill the monster. Now, you don't have a sword.")
      hasSword = False
      grid[startRow][startCol] = EMPTY
    elif hasSword == False:
      print("You have run into a monster!!!")
      print("You don't have any sword to kill the monster. You died.")
      break
  elif foundInCell == "p":
    if hasPotion == True:
      print("There is a potion here but you have already have one.")
    else:
      hasPotion = True
      grid[startRow][startCol] = EMPTY
      print("You have found a potion.")

  elif foundInCell == "s":
    if hasSword == True:
      print("There is a sword here but you have already have one.")
    else:
      hasSword = True
      grid[startRow][startCol] = EMPTY
      print("You have found a sword.")

  elif foundInCell == "v":
    if hasPotion == True:
      print("You have run into a venom!!!")
      print("You have used your potion to recover from the venom. Now, you don't have a potion.")
      hasPotion = False
      grid[startRow][startCol] = EMPTY
    else:
      print("You have run into a venom!!!")
      print("You don't have any portion to recover from the venom. You died.")
      break

