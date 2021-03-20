import os
import msvcrt   # Microsoft Visual C/C++ Runtime Library. for getch()
import sys      # for exit()
import random

# Global variables:
UP      = b'H' 
RIGHT   = b'M'
DOWN    = b'P'
LEFT    = b'K'
ESC     = b'\x1b'
ENTER   = b'\r'
ARROWKEYS    = (UP, RIGHT, DOWN, LEFT)

class newBoard():
    
    def __init__(self, map):
        self.map = map

    def cvrtList(self):

        inFile = open(self.map, "r")
        board = inFile.read().splitlines() # splitlines is to exclude the '\n'
        inFile.close()
        
        rows = len(board)
        cols = len(board[0])
        # To convert each line os string into a list, 
        # because string is immutable
        for i in range(rows) :
            board[i] = list(board[i])
        self.board = board
        self.rows  = rows
        self.cols  = cols
    
    # Clear the screen
    def ClearScreen(self):
        
        if os.name == "nt":
            os.system("cls");
        else:
            os.system("clear");

    def showBoard(self):
        self.ClearScreen()
        for i in range(self.rows) :
            for j in range(self.cols) :
                print(self.board[i][j], end="")
            print()

    def cvrtStr(self):
        saveBoard = ""
        for ele in self.board:
            for i in range(self.cols):
                saveBoard += ele[i]
            saveBoard += '\n'
        print(saveBoard)

    def stopGame(self) :
    
        print("\t\tGameOver")
        os.system("PAUSE")
        sys.exit(0)

    '''def openFile(self):
        
        if write:
            inFile = open(x, "w")
            inFile.write(y)
            inFile.close()
        else:
            inFile = open(x, "r")
            file = inFile.read()
            inFile.close()'''

class newMoves():

    def __init__(self, board, sprite, step):
        self.board  = board
        self.sprite = sprite #'^'
        self.step   = step
        self.limitList()
        self.moveX  = 1
        self.moveY  = 1

    def limitList(self):
        #limit
        step = (self.step)
        limit = []
        rowY = 0
        for lineNum in range(len(self.board)) :
            colX = 0
            for abc in range(len(self.board[rowY])) :
                if self.board[rowY][colX] in step :
                    object1 = [rowY,colX]
                    limit.append(object1)
                colX = colX + 1
            rowY = rowY + 1
        self.limit = limit

    def find(self, x) :
    
        rowY = 0
        for lineNum in range(len(self.board)) :
            colX = 0
            for abc in range(len(self.board[rowY])) :
                if self.board[rowY][colX] in x :
                    return rowY, colX
                colX = colX + 1
            rowY = rowY + 1
            
        return -1, -1 #if the object does not exist
    
    def randomMove(self):

        coY, coX = self.find(self.sprite)
        self.board[coY][coX] = self.step
        before = [coY , coX]
        
        z = random.randrange(5)
        while coY != -1 and coX != -1:
            if z == 0        : 
                if [coY-self.moveY, coX] in self.limit:
                    coY -= self.moveY
                    break
                else:
                    z = random.randrange(5)
                    continue
            elif z == 1      :
                if [coY, coX+self.moveX] in self.limit:
                    coX += self.moveX
                    break
                else:
                    z = random.randrange(5)
                    continue
            elif z == 2      :
                if [coY+self.moveY, coX] in self.limit:
                    coY += self.moveY
                    break
                else:
                    z = random.randrange(5)
                    continue
            elif z == 3      :
                if [coY, coX-self.moveX] in self.limit:
                    coX -= self.moveX
                    break
                else:
                    z = random.randrange(5)
                    continue
            elif z == 4      :
                break
            else:
                z = random.randrange(5)
                continue
        self.board[coY][coX] = self.sprite
        self.limitList()

    def guideMove(self):
    
        key = msvcrt.getch()
        if key == ESC:
            sys.exit()
        while key not in ARROWKEYS:
            key = msvcrt.getch()
            if key == ESC:
                sys.exit()
        coY, coX = self.find(self.sprite)
        current = [coY, coX]
    
        self.board[coY][coX] = self.step
        if key == UP        : 
            if [coY-self.moveY, coX] in self.limit:
                coY -= self.moveY
        elif key == RIGHT   :
            if [coY, coX+self.moveX] in self.limit:
                coX += self.moveX
        elif key == DOWN    :
            if [coY+self.moveY, coX] in self.limit:
                coY += self.moveY
        elif key == LEFT    :
            if [coY, coX-self.moveX] in self.limit:
                coX -= self.moveX
        self.board[coY][coX] = self.sprite
        self.limitList()
