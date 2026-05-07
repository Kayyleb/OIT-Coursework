using System;
using System.Collections.Generic;
using System.Text;

namespace Lab_Six
{
    public class InventoryItem
    {
        public string ImageUrl { get; set; }

        public InventoryItem(string imageUrl)
        {
            ImageUrl = imageUrl;
        }
    }
}
