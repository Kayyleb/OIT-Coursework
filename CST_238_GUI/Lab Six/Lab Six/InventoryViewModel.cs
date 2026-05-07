using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text;

namespace Lab_Six
{
    public class InventoryViewModel : INotifyPropertyChanged
    {
        public ObservableCollection<InventoryItem> Items { get; set; }
            = new ObservableCollection<InventoryItem>();

        public event PropertyChangedEventHandler? PropertyChanged;

        void OnPropertyChanged([CallerMemberName] string name = null)
            => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));

        public void AddItem(string imageFile)
        {
            Items.Add(new InventoryItem(imageFile));
            OnPropertyChanged(nameof(Items));
        }
    }
}
