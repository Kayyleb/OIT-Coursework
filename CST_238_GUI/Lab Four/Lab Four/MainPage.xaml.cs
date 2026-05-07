using Lab_Four.Drawables;
using Microsoft.Maui.Graphics.Platform;
using System.Threading.Tasks;

namespace Lab_Four
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        // file menu click functions
        private async void OpenClick(object sender, EventArgs e)
        {
            string fileName = await DisplayPromptAsync("File Open", "FileName" , initialValue: ".png");
            string filePath = Path.Combine(FileSystem.AppDataDirectory, fileName);
            using (Stream stream = File.OpenRead(filePath))
            {
                Microsoft.Maui.Graphics.IImage img =
                    (Microsoft.Maui.Graphics.IImage)PlatformImage.FromStream(stream);
                myCanvas.setImage(img);
            }
        }

        private async void SaveClick(object sender, EventArgs e)
        {
            string fileName = await DisplayPromptAsync("File Save", "Filename", initialValue: ".png");
            string filePath = Path.Combine(FileSystem.AppDataDirectory, fileName);
            IScreenshotResult screenshot = await myCanvas.CaptureAsync();
            if (screenshot != null)
            {
                using (var fileStream = File.OpenWrite(filePath))
                {
                    await screenshot.CopyToAsync(fileStream);
                }
            }
        }

        private async void ExitClick(object sender, EventArgs e)
        {
            Application.Current.Quit();
        }

        private async void setShape(object sender, EventArgs e)
        {
            var item = sender as MenuFlyoutItem;
            if (item?.Text == "Line")
            {
                myCanvas.CurrentShape = 0;
            }
            else if (item?.Text == "Rectangle")
            {
                myCanvas.CurrentShape = 1;
            }
            else if (item?.Text == "Oval")
            {
                myCanvas.CurrentShape = 2;
            }
        }

        private async void setStrokeColor(object sender, EventArgs e)
        {
            var menu = (MenuFlyoutItem)sender;
            myCanvas.SetStrokeColor(menu.Text);
        }

        private async void setFillColor(object sender, EventArgs e)
        {
            var menu = (MenuFlyoutItem)sender;
            myCanvas.SetFillColor(menu.Text);
        }

        private async void AboutClick(object sender, EventArgs e)
        {
            await DisplayAlert("About", "Kayleb Coook \n Spring26", "Dismiss");
        }

        private async void PointerGestureRecognizer_PointerPressed(object sender, PointerEventArgs e)
        {
            myCanvas.setStartPoint((Point)e.GetPosition((View)sender));
        }

        private async void PointerGestureRecognizer_PointerReleased(object sender, PointerEventArgs e)
        {
            myCanvas.setEndPoint((Point)e.GetPosition((View)sender));
            myCanvas.addShape();
            myCanvas.Invalidate();
        }

    }
}
