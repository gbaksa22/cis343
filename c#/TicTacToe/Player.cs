using System;

public class Player
{
    // Player's name (e.g., "Player 1", "NPC")
    public string Name { get; set; }

    // Player's marker ('X' or 'O')
    public char Marker { get; set; }

    // Flag indicating whether the player is an NPC
    public bool IsNPC { get; set; }

    // Constructor to initialize a Player instance
    public Player(string name, char marker, bool isNPC)
    {
        Name = name;
        Marker = marker;
        IsNPC = isNPC;
    }

    // Method to get the player's move
    public int GetMove(char[,] board)
    {
        if (IsNPC)
        {
            // NPC generates a random move
            Random rnd = new Random();
            int move;

            // Ensure the move is valid
            do
            {
                move = rnd.Next(1, 10); // Random number between 1 and 9
            } while (!IsValidMove(board, move));

            return move;
        }
        else
        {
            // Prompt human player for input
            Console.Write($"{Name}, enter your move (1-9): ");
            int move;

            // Validate human input
            while (!int.TryParse(Console.ReadLine(), out move) || !IsValidMove(board, move))
            {
                Console.Write("Invalid move. Try again: ");
            }

            return move;
        }
    }

    // Helper method to validate the move
    private bool IsValidMove(char[,] board, int move)
    {
        // Convert the move to board coordinates
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if the cell is empty
        return board[row, col] != 'X' && board[row, col] != 'O';
    }
}
