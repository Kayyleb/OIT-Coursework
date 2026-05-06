namespace EmployeeCollection
{
    public class Employee
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

        public void DisplayEmployee()
        {
            Console.WriteLine ("Name: " + Name + 
                              " SSN: " + SSN + 
                              " Salary: " + Salary + "\n");
        }

    }
}
