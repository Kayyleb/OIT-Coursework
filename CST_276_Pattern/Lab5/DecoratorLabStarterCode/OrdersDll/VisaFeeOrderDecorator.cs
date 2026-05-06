using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class VisaFeeOrderDecorator : OrderDecorator
    {
        public VisaFeeOrderDecorator(AbstractOrderBase inner) : base(inner) { }

        public override double GetTotalCost() => inner.GetTotalCost() + 2.00;

        public override void PrintOrderItems()
        {
            Console.WriteLine("Payment Method: Visa (+$2.00 processing)");
            base.PrintOrderItems();
            Console.WriteLine("Grand Total with Visa Fee {0:C}", GetTotalCost());
            Console.WriteLine();
        }
    }
}
