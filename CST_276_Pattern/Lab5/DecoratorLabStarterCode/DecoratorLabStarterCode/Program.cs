using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OrdersDll;

namespace DecoratorLabStarterCode
{
    class Program
    {
        static void Main(string[] args)
        {
            AbstractOrderBase order = new Order();

            order.AddItem("BroncoHats", 2, 1.5, 0.2);
            order.AddItem("BroncoGloves", 1, 3.0, 0.5);
            order.AddItem("BroncoSocks", 6, 1.9, 0.1);
            order.AddItem("BroncoBanners", 3, 8.0, 1.5);
            order.AddItem("BroncoFootBalls", 4, 5.6, 0.6);
            order.AddItem("BroncoJerseys", 2, 2.3, 0.4);

            Console.WriteLine("Base order:");
            order.PrintOrderItems(); // $68.40

            Console.WriteLine("Express:");
            var express = new ExpressDeliveryOrderDecorator(order);
            express.PrintOrderItems(); // $72.40

            Console.WriteLine("Visa:");
            var visa = new VisaFeeOrderDecorator(order);
            visa.PrintOrderItems(); // $70.40

            Console.WriteLine("AmEx:");
            var amex = new AmexFeeOrderDecorator(order);
            amex.PrintOrderItems(); // $73.40

            Console.WriteLine("Express + AmEx together:");
            var expressAmex = new AmexFeeOrderDecorator(new ExpressDeliveryOrderDecorator(order));
            expressAmex.PrintOrderItems(); // $77.40

            Console.ReadLine();
        }
    }
}
