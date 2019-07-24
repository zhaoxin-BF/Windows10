using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Models
{
    public class Topic
    {
        public int Tid { get; set; }
        public string Uid { get; set; }
        public string Create_time { get; set; }
        public string Context { get; set; }
        public string Title { get; set; }
        public string Introduce { get; set; }
        public int Recommend { get; set; }
    }
}
