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
        BuildGrid();
        PlaceItems();
        PlacePlayer();

        this.HandlerChanged += (s, e) =>
        {
            if (Handler?.PlatformView is Microsoft.UI.Xaml.UIElement element)
            {
                element.KeyDown += (sender, args) =>
                {
                    switch (args.Key)
                    {
                        case Windows.System.VirtualKey.Up:
                            Up(null, null); break;
                        case Windows.System.VirtualKey.Down:
                            Down(null, null); break;
                        case Windows.System.VirtualKey.Left:
                            Left(null, null); break;
                        case Windows.System.VirtualKey.Right:
                            Right(null, null); break;
                    }
                };
            }
        };
    }

    void BuildGrid()
    {
        for (int i = 0; i < GridSize; i++)
        {
            GameGrid.RowDefinitions.Add(new RowDefinition { Height = CellSize });
            GameGrid.ColumnDefinitions.Add(new ColumnDefinition { Width = CellSize });
        }

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
                else
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

    void PlaceItems()
    {
        var key = new GameItem("key.png", 2, 3, isCollectible: true);
        AddBoardItem(key);

        var goldKey = new GameItem("goldkey.png", 5, 5, isCollectible: true);
        AddBoardItem(goldKey);

        var door = new GameItem("door.png", 0, 3); // col 0 = left wall, row 3 = middle
        AddBoardItem(door);
    }

    void AddBoardItem(GameItem item)
    {
        boardItems.Add(item);
        Grid.SetRow(item, item.GameRow);
        Grid.SetColumn(item, item.GameColumn);
        GameGrid.Children.Add(item);
    }

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

    void CheckInventory()
    {
        var viewModel = BindingContext as InventoryViewModel;

        foreach (var item in boardItems.ToList())
        {
            if (item.IsCollectible
                && item.IsVisible
                && item.GameRow == owl.GameRow
                && item.GameColumn == owl.GameColumn)
            {
                item.IsVisible = false;
                viewModel?.AddItem(item.ImageUrl);
            }
        }
    }
}
