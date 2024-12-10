using System;

class Program
{
    static void Main()
    {
        // Display welcome message
        Console.WriteLine("Welcome to Tic Tac Toe!");

        // Prompt the user to select the number of players
        Console.WriteLine("Select number of players (0 = NPC vs NPC, 1 = User vs NPC, 2 = User vs User): ");

        int playerCount;

        // Validate user input for number of players
        while (!int.TryParse(Console.ReadLine(), out playerCount) || playerCount < 0 || playerCount > 2)
        {
            Console.WriteLine("Invalid input. Please enter 0, 1, or 2: ");
        }

        // Create player instances based on the number of players
        Player player1 = new Player("Player 1", 'X', playerCount == 0);
        Player player2 = playerCount switch
        {
            0 => new Player("Player 2", 'O', true),  // NPC vs NPC
            1 => new Player("NPC", 'O', true),       // User vs NPC
            2 => new Player("Player 2", 'O', false),// User vs User
            _ => throw new NotImplementedException(),
        };

        // Instantiate the Game class and start the game
        Game game = new Game(player1, player2);
        game.Start();
    }
}
