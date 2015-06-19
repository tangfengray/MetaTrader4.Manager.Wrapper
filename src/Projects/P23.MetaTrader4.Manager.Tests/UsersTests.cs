using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class UsersTests
    {
        [TestMethod]
        public void ConstructorTest()
        {
            using (var mt = new ClrWrapper(new ConnectionParameters { Login = 0, Password = "", Server = "" }, @"D:\ProgrammingWorkspace\MetaTrader4.Manager.Wrapper\src\Libraries\mtmanapi\mtmanapi.dll"))
            {
                var users = mt.UserRecordsRequest(new List<int> { 1, 2 });
                Assert.AreEqual(2, users.Count);
            }
        }
    }
}
