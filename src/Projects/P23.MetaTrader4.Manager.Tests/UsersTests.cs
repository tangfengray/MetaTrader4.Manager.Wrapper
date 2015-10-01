using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class UsersTests
    {
        [TestMethod]
        public void UsersRequest_Invoke_UsersReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                var users = mt.UsersRequest();
                Assert.IsTrue(users.Count > 0);
            }
        }
    }
}
