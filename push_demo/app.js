// Generated by CoffeeScript 1.9.0
$(function() {
  NCMB.initialize("","");
  return $("form").on("submit", function(e) {
    var message;
	var title;
    e.preventDefault();
	//title = $("#title").val();
	title = $("#title").val();
    message = $("#message").val();
    NCMB.Push.send({
	title: title,
      message: message,
      immediateDeliveryFlag: true,
      target: ['android'],
      searchCondition: {}
    }).then(function(e) {
      console.info("success", e);
      $(".message").addClass("alert alert-success").html("作成されました");
      return setTimeout(function(e) {
        return $(".message").removeClass("alert alert-success").html("");
      }, 3000);
    }, function(e) {
      return console.error("error", e);
    });
    return false;
  });
});
