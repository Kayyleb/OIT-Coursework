namespace InternalCompositeIteratorC
{
    public class Employee : CompanyComponent
    {
        public string Name { get; set; }
        public string SSN { get; set; }
        public double Salary { get; set; }

        public Employee(string N, string SS, double S)
        {
            Name = N;
            SSN = SS;
            Salary = S;
        }

        public override string GetName()
        {
            return Name;
        }
        public override void Display()
        {
            Console.WriteLine ("Name: " + Name + 
                              " SSN: " + SSN + 
                              " Salary: " + Salary + "\n");
        }

        public override void Accept(IVisitor visitor)
        {
            visitor.Visit(this);
        }

    }
}
