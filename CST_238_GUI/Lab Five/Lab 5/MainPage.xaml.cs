using Microsoft.Maui.Controls;
using Microsoft.Maui.Layouts;

namespace Lab_5
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();

            // Part 3: add at least 10 woodchucks
            for (int i = 0; i < 10; i++)
            {
                var chuck = new Woodchuck(grassLayout);
                grassLayout.Children.Add(chuck);
            }
        }
    }
}