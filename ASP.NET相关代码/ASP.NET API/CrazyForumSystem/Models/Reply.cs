using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Models
{
    public class Reply
    {
        public int Rid { get; set; }
        public int Rtid { get; set; }
        public string Ruid { get; set; }
        public string Rphoto { get; set; }
        public string Rtime { get; set; }
        public string Rcontext { get; set; }
    }
}
