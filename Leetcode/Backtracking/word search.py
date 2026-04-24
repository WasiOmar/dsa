class Solution:
    def walk(self, board, word, x, y, pos):
        if pos == len(word):
            return True

        if (x < 0 or y < 0 or 
            x >= len(board) or y >= len(board[0]) or 
            board[x][y] != word[pos]):
            return False

        ch = board[x][y]
        board[x][y] = '*'  # visited

        ok = (self.walk(board, word, x+1, y, pos+1) or
              self.walk(board, word, x-1, y, pos+1) or
              self.walk(board, word, x, y+1, pos+1) or
              self.walk(board, word, x, y-1, pos+1))

        board[x][y] = ch  # backtrack

        return ok

    def exist(self, board, word):
        h, w = len(board), len(board[0])

        for i in range(h):
            for j in range(w):
                if self.walk(board, word, i, j, 0):
                    return True
        return False