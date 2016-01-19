using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class NotificationTest
    {
        [TestMethod]
        public void NotificationSend()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                var result = mt.NotificationsSend("ids", "message");
                Assert.AreEqual(0, result);
            }
        }
    }
}
