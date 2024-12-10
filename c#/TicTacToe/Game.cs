using System;

public class Game
{
    // Represents the Tic Tac Toe board
    private char[,] board = {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' }
    };

    // Player instances for the game
    private Player player1;
    private Player player2;

    // Constructor to initialize the Game with players
    public Game(Player player1, Player player2)
    {
        this.player1 = player1;
        this.player2 = player2;
    }

    // Method to start the game loop
    public void Start()
    {
        int turn = 0; // Turn counter
        Player currentPlayer = player1;

        // Game loop: continue until 9 turns or a win
        while (turn < 9)
        {
            Console.Clear(); // Clear the console for a clean display
            DisplayBoard();  // Show the current state of the board

            // Prompt the current player for their move
            Console.WriteLine($"{currentPlayer.Name}'s turn ({currentPlayer.Marker})");
            int move = currentPlayer.GetMove(board);

            // Place the marker on the board
            PlaceMarker(currentPlayer.Marker, move);

            // Check for a win condition
            if (CheckWin(currentPlayer.Marker))
            {
                Console.Clear();
                DisplayBoard();
                Console.WriteLine($"{currentPlayer.Name} wins!"); // Announce the winner
                return;
            }

            // Switch to the next player
            currentPlayer = (currentPlayer == player1) ? player2 : player1;
            turn++; // Increment the turn counter
        }

        // If all turns are used and no winner, it's a draw
        Console.Clear();
        DisplayBoard();
        Console.WriteLine("It's a draw!");
    }

    // Method to display the current state of the board
    private void DisplayBoard()
    {
        Console.WriteLine("-------------");
        for (int i = 0; i < 3; i++)
        {
            Console.WriteLine($"| {board[i, 0]} | {board[i, 1]} | {board[i, 2]} |");
            Console.WriteLine("-------------");
        }
    }

    // Method to place a player's marker on the board
    private void PlaceMarker(char marker, int move)
    {
        // Convert move to board coordinates
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Update the board with the player's marker
        board[row, col] = marker;
    }

    // Method to check if a player has won
    private bool CheckWin(char marker)
    {
        // Check rows and columns for a winning condition
        for (int i = 0; i < 3; i++)
        {
            if ((board[i, 0] == marker && board[i, 1] == marker && board[i, 2] == marker) ||
                (board[0, i] == marker && board[1, i] == marker && board[2, i] == marker))
                return true;
        }

        // Check diagonals for a winning condition
        if ((board[0, 0] == marker && board[1, 1] == marker && board[2, 2] == marker) ||
            (board[0, 2] == marker && board[1, 1] == marker && board[2, 0] == marker))
            return true;

        return false; // No winning condition met
    }
}
