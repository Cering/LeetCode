#
# @lc app=leetcode id=1275 lang=python3
#
# [1275] Find Winner on a Tic Tac Toe Game
#
# https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/
#
# algorithms
# Easy (56.51%)
# Likes:    25
# Dislikes: 12
# Total Accepted:    3.8K
# Total Submissions: 6.8K
# Testcase Example:  '[[0,0],[2,0],[1,1],[2,1],[2,2]]'
#
# Tic-tac-toe is played by two players A and B on a 3 x 3 grid.
# 
# Here are the rules of Tic-Tac-Toe:
# 
# 
# Players take turns placing characters into empty squares (" ").
# The first player A always places "X" characters, while the second player B
# always places "O" characters.
# "X" and "O" characters are always placed into empty squares, never on filled
# ones.
# The game ends when there are 3 of the same (non-empty) character filling any
# row, column, or diagonal.
# The game also ends if all squares are non-empty.
# No more moves can be played if the game is over.
# 
# 
# Given an array moves where each element is another array of size 2
# corresponding to the row and column of the grid where they mark their
# respective character in the order in which A and B play.
# 
# Return the winner of the game if it exists (A or B), in case the game ends in
# a draw return "Draw", if there are still movements to play return "Pending".
# 
# You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the
# grid is initially empty and A will play first.
# 
# 
# Example 1:
# 
# 
# Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
# Output: "A"
# Explanation: "A" wins, he always plays first.
# "X  "    "X  "    "X  "    "X  "    "X  "
# "   " -> "   " -> " X " -> " X " -> " X "
# "   "    "O  "    "O  "    "OO "    "OOX"
# 
# 
# Example 2:
# 
# 
# Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
# Output: "B"
# Explanation: "B" wins.
# "X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
# "   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
# "   "    "   "    "   "    "   "    "   "    "O  "
# 
# 
# Example 3:
# 
# 
# Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
# Output: "Draw"
# Explanation: The game ends in a draw since there are no moves to make.
# "XXO"
# "OOX"
# "XOX"
# 
# 
# Example 4:
# 
# 
# Input: moves = [[0,0],[1,1]]
# Output: "Pending"
# Explanation: The game has not finished yet.
# "X  "
# " O "
# "   "
# 
# 
# 
# Constraints:
# 
# 
# 1 <= moves.length <= 9
# moves[i].length == 2
# 0 <= moves[i][j] <= 2
# There are no repeated elements on moves.
# moves follow the rules of tic tac toe.
# 
#

# @lc code=start
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        steps = len(moves)
        if steps <= 0:
            return "Draw"
        grid = [0] * 9
        for i in range(steps):
            grid[moves[i][0]*3+moves[i][1]] = 1 if i%2==0 else -1
        check = [
            grid[0]+grid[1]+grid[2],
            grid[3]+grid[4]+grid[5],
            grid[6]+grid[7]+grid[8],
            grid[0]+grid[3]+grid[6],
            grid[1]+grid[4]+grid[7],
            grid[2]+grid[5]+grid[8],
            grid[0]+grid[4]+grid[8],
            grid[2]+grid[4]+grid[6]
        ]
        if 3 in check:
            return 'A'
        elif -3 in check:
            return 'B'
        elif not all(grid):
            return 'Draw'
        else:
            return 'Pending'
        
# @lc code=end
