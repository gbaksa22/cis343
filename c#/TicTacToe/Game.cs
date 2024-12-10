using System;

public class Game
{
    private char[,] board = {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' }
    };

    private Player player1;
    private Player player2;

    public Game(Player player1, Player player2)
    {
        this.player1 = player1;
        this.player2 = player2;
    }

    public void Start()
    {
        int turn = 0;
        Player currentPlayer = player1;

        while (turn < 9)
        {
            Console.Clear();
            DisplayBoard();
            Console.WriteLine($"{currentPlayer.Name}'s turn ({currentPlayer.Marker})");
            int move = currentPlayer.GetMove(board);
            PlaceMarker(currentPlayer.Marker, move);

            if (CheckWin(currentPlayer.Marker))
            {
                Console.Clear();
                DisplayBoard();
                Console.WriteLine($"{currentPlayer.Name} wins!");
                return;
            }

            currentPlayer = (currentPlayer == player1) ? player2 : player1;
            turn++;
        }

        Console.Clear();
        DisplayBoard();
        Console.WriteLine("It's a draw!");
    }

    private void DisplayBoard()
    {
        Console.WriteLine("-------------");
        for (int i = 0; i < 3; i++)
        {
            Console.WriteLine($"| {board[i, 0]} | {board[i, 1]} | {board[i, 2]} |");
            Console.WriteLine("-------------");
        }
    }

    private void PlaceMarker(char marker, int move)
    {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row, col] = marker;
    }

    private bool CheckWin(char marker)
    {
        // Check rows and columns
        for (int i = 0; i < 3; i++)
        {
            if ((board[i, 0] == marker && board[i, 1] == marker && board[i, 2] == marker) ||
                (board[0, i] == marker && board[1, i] == marker && board[2, i] == marker))
                return true;
        }

        // Check diagonals
        if ((board[0, 0] == marker && board[1, 1] == marker && board[2, 2] == marker) ||
            (board[0, 2] == marker && board[1, 1] == marker && board[2, 0] == marker))
            return true;

        return false;
    }
}
