function push_demo(){

	var NCMB = require("ncmb");
	var ncmb = new NCMB("app key","client key");
	
	// send push notification
	var push = new ncmb.Push()
//	push.set("title", "Hello, NCMB!")
	push.set("immediateDeliveryFlag", true)
	    .set("title", "test push")
	    .set("message", "message")
	    .set("target", ['android'])
	    //.set("serchCodition", {})
	    .send()
	    .then(function(push){
	      console.log(push);
	    })
	    .catch(function(err){
	      console.log(err);
	    });

}

push_demo();


