using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    abstract public class AbstractOrderBase
    {
        protected readonly List<OrderItem> items = new List<OrderItem>();

        public abstract void AddItem(string productCode, int quantity, double cost, double weight);
        public abstract void PrintOrderItems();
        public abstract double GetTotalCost();
    }
}
