using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Welcome to Tic Tac Toe!");
        Console.WriteLine("Select number of players (0 = NPC vs NPC, 1 = User vs NPC, 2 = User vs User): ");
        
        int playerCount;
        while (!int.TryParse(Console.ReadLine(), out playerCount) || playerCount < 0 || playerCount > 2)
        {
            Console.WriteLine("Invalid input. Please enter 0, 1, or 2: ");
        }

        Player player1 = new Player("Player 1", 'X', playerCount == 0);
        Player player2 = playerCount switch
        {
            0 => new Player("Player 2", 'O', true),
            1 => new Player("NPC", 'O', true),
            2 => new Player("Player 2", 'O', false),
            _ => throw new NotImplementedException(),
        };

        Game game = new Game(player1, player2);
        game.Start();
    }
}
