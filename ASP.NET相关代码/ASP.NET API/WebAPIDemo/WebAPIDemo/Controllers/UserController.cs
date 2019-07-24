using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using WebAPIDemo.Models;

namespace WebAPIDemo.Controllers
{
    public class UserController : ApiController
    {     
        public string Login(User user)
        {
            return "ok";
        }
    }
}
