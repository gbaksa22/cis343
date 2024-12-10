using System;

public class Player
{
    public string Name { get; set; }
    public char Marker { get; set; }
    public bool IsNPC { get; set; }

    public Player(string name, char marker, bool isNPC)
    {
        Name = name;
        Marker = marker;
        IsNPC = isNPC;
    }

    public int GetMove(char[,] board)
    {
        if (IsNPC)
        {
            Random rnd = new Random();
            int move;
            do
            {
                move = rnd.Next(1, 10); // Random move 1-9
            } while (!IsValidMove(board, move));
            return move;
        }
        else
        {
            Console.Write($"{Name}, enter your move (1-9): ");
            int move;
            while (!int.TryParse(Console.ReadLine(), out move) || !IsValidMove(board, move))
            {
                Console.Write("Invalid move. Try again: ");
            }
            return move;
        }
    }

    private bool IsValidMove(char[,] board, int move)
    {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        return board[row, col] != 'X' && board[row, col] != 'O';
    }
}
