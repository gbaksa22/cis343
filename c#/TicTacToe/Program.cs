// See https://aka.ms/new-console-template for more information
using System;

class Program
{
    static char[,] board = {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' }
    };

    static char currentPlayer = 'X';

    static void Main()
    {
        int turn = 0;
        bool gameRunning = true;

        while (gameRunning && turn < 9)
        {
            Console.Clear();
            DisplayBoard();
            Console.WriteLine($"Player {currentPlayer}, choose your move (1-9): ");
            
            string input = Console.ReadLine();
            if (int.TryParse(input, out int move) && move >= 1 && move <= 9)
            {
                if (PlaceMarker(move))
                {
                    if (CheckWin())
                    {
                        Console.Clear();
                        DisplayBoard();
                        Console.WriteLine($"Player {currentPlayer} wins!");
                        gameRunning = false;
                    }
                    else
                    {
                        SwitchPlayer();
                        turn++;
                    }
                }
                else
                {
                    Console.WriteLine("Invalid move, try again.");
                }
            }
            else
            {
                Console.WriteLine("Invalid input, try again.");
            }
        }

        if (turn == 9 && gameRunning)
        {
            Console.Clear();
            DisplayBoard();
            Console.WriteLine("It's a draw!");
        }
    }

    static void DisplayBoard()
    {
        Console.WriteLine("-------------");
        for (int i = 0; i < 3; i++)
        {
            Console.WriteLine($"| {board[i, 0]} | {board[i, 1]} | {board[i, 2]} |");
            Console.WriteLine("-------------");
        }
    }

    static bool PlaceMarker(int move)
    {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row, col] != 'X' && board[row, col] != 'O')
        {
            board[row, col] = currentPlayer;
            return true;
        }
        return false;
    }

    static void SwitchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    static bool CheckWin()
    {
        // Check rows and columns
        for (int i = 0; i < 3; i++)
        {
            if ((board[i, 0] == currentPlayer && board[i, 1] == currentPlayer && board[i, 2] == currentPlayer) ||
                (board[0, i] == currentPlayer && board[1, i] == currentPlayer && board[2, i] == currentPlayer))
                return true;
        }

        // Check diagonals
        if ((board[0, 0] == currentPlayer && board[1, 1] == currentPlayer && board[2, 2] == currentPlayer) ||
            (board[0, 2] == currentPlayer && board[1, 1] == currentPlayer && board[2, 0] == currentPlayer))
            return true;

        return false;
    }
}
