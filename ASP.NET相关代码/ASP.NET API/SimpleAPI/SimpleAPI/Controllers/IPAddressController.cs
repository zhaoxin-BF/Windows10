using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using SimpleAPI.Models;

namespace SimpleAPI.Controllers
{
    public class IPAddressController : ApiController
    {
            //Ilist<Beam> beamList = new List<Beam>();
            //beamList.Add(new Beam { Name="xxx", Age=18 });
        private static IList<Address> addresses = new List<Address>
        { 
            new Address(){ IPAddress="1.91.38.31", Province="北京市", City="北京市" },   
            new Address(){ IPAddress = "210.75.225.254", Province = "上海市", City = "上海市"  },
        };
        public IEnumerable<Address> GetIPAddresses()
        {

            return addresses;
        }

        public Address GetIPAddressByIP(string IP)
        {
            return addresses.FirstOrDefault(x => x.IPAddress == IP);
        }
    }
}
