namespace Lab_Six;
public partial class MainPage : ContentPage
{
    const int GridSize = 8;
    const int CellSize = 60;

    private GameItem owl;
    private List<GameItem> boardItems = new();

    public MainPage()
    {
        InitializeComponent();
        BuildGrid(); // build grid when the game starts
        PlaceItems(); // then place items
        PlacePlayer(); // then the player

        // to handle arrow key input
        this.HandlerChanged += (s, e) =>
        {
            if (Handler?.PlatformView is Microsoft.UI.Xaml.UIElement element)
            {
                element.KeyDown += (sender, args) =>
                {
                    switch (args.Key)
                    {
                        case Windows.System.VirtualKey.Up:
                            Up(null, null); 
                            break;
                        case Windows.System.VirtualKey.Down:
                            Down(null, null); 
                            break;
                        case Windows.System.VirtualKey.Left:
                            Left(null, null); 
                            break;
                        case Windows.System.VirtualKey.Right:
                            Right(null, null); 
                            break;
                    }
                };
            }
        };
    }

    // function to build the grid with walls 
    void BuildGrid()
    {
        for (int i = 0; i < GridSize; i++) // create the rows and columns of the grid
        {
            GameGrid.RowDefinitions.Add(new RowDefinition { Height = CellSize });
            GameGrid.ColumnDefinitions.Add(new ColumnDefinition { Width = CellSize });
        }

        // for loop to build the walls of the grid
        for (int row = 0; row < GridSize; row++)
        {
            for (int col = 0; col < GridSize; col++)
            {
                bool isWall = row == 0 || row == GridSize - 1
                           || col == 0 || col == GridSize - 1;

                View cell;
                if (isWall)
                {
                    cell = new Image
                    {
                        Source = "brick.png",
                        WidthRequest = CellSize,
                        HeightRequest = CellSize,
                        Aspect = Aspect.Fill
                    };
                }
                else // if we are not on the perimiter, them fill with black for the floor
                {
                    cell = new BoxView
                    {
                        Color = Color.FromArgb("#000000"),
                        WidthRequest = CellSize,
                        HeightRequest = CellSize
                    };
                }

                Grid.SetRow(cell, row);
                Grid.SetColumn(cell, col);
                GameGrid.Children.Add(cell);
            }
        }
    }

    // function to place the items on the grid
    void PlaceItems()
    {
        var key = new GameItem("key.png", 2, 3, isCollectible: true); // place blue key
        AddBoardItem(key);

        var goldKey = new GameItem("goldkey.png", 5, 5, isCollectible: true); // place gold key
        AddBoardItem(goldKey);

        var door = new GameItem("door.png", 0, 4); // place door somewhat in the middle of the left wall
        AddBoardItem(door);
    }

    // function actually adds the item image to the grid
    void AddBoardItem(GameItem item)
    {
        boardItems.Add(item);
        Grid.SetRow(item, item.GameRow);
        Grid.SetColumn(item, item.GameColumn);
        GameGrid.Children.Add(item);
    }

    // function to the place the player
    void PlacePlayer()
    {
        owl = new GameItem("owl.png", 3, 4);
        GameGrid.BindingContext = owl;
        owl.SetBinding(Grid.RowProperty, "GameRow");
        owl.SetBinding(Grid.ColumnProperty, "GameColumn");
        GameGrid.Children.Add(owl);
    }

    private void Up(object sender, EventArgs e)
    {
        if (owl.GameRow > 1) { owl.GameRow--; CheckInventory(); }
    }

    private void Down(object sender, EventArgs e)
    {
        if (owl.GameRow < GridSize - 2) { owl.GameRow++; CheckInventory(); }
    }

    private void Left(object sender, EventArgs e)
    {
        if (owl.GameColumn > 1) { owl.GameColumn--; CheckInventory(); }
    }

    private void Right(object sender, EventArgs e)
    {
        if (owl.GameColumn < GridSize - 2) { owl.GameColumn++; CheckInventory(); }
    }

    // this function checks and updates ionventory when you interact with either one of the key's images 
    void CheckInventory()
    {
        var viewModel = BindingContext as InventoryViewModel;

        foreach (var item in boardItems.ToList())
        {
            if (item.IsCollectible && item.IsVisible
                && item.GameRow == owl.GameRow
                && item.GameColumn == owl.GameColumn)
            {
                item.IsVisible = false;
                viewModel?.AddItem(item.ImageUrl);
            }
        }

        CheckWin();
    }

    // checks win condition of the game and dispays win label
    void CheckWin()
    {
        var door = boardItems.FirstOrDefault(i => i.ImageUrl == "door.png");
        if (door != null && owl.GameColumn == 1 && owl.GameRow == door.GameRow)
        {
            WinLabel.IsVisible = true;
        }
    }
}
