using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text;

namespace Lab_Six
{
    public class GameItem : Image, INotifyPropertyChanged
    {
        public const int CellSize = 60;

        private int _x;
        private int _y;

        public string ImageUrl { get; set; }
        public bool IsCollectible { get; set; }

        public new event PropertyChangedEventHandler? PropertyChanged;

        public GameItem(string imageUrl, int col, int row, bool isCollectible = false)
        {
            ImageUrl = imageUrl;
            IsCollectible = isCollectible;
            Source = imageUrl;
            WidthRequest = CellSize;
            HeightRequest = CellSize;
            Aspect = Aspect.Fill;
            _x = col;
            _y = row;
        }

        public int GameColumn
        {
            get => _x;
            set { _x = value; OnPropertyChanged(); }
        }

        public int GameRow
        {
            get => _y;
            set { _y = value; OnPropertyChanged(); }
        }

        void OnPropertyChanged([CallerMemberName] string name = null)
            => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
    }
}
