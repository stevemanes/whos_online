// $Id: whos_online.js 258 2009-01-15 15:41:12Z root $
(function ($) {
Drupal.behaviors.whos_online = {
	attach: function(context) {
    	// Set up.
    	$("#users_header").addClass('header_collapsed');
    	$("#users_body").hide();

    	$("#guests_header").addClass('header_collapsed');
    	$("#guests_body").hide();

    	$("#bots_header").addClass('header_collapsed');
    	$("#bots_body").hide();

    	$("#users_header").toggle(function(e){
//        	alert('change to show');
        	$("#users_header").removeClass('header_collapsed');
        	$("#users_header").addClass('header_expanded');
        	$("#users_body").show();
    	}, function(e) {
//        	alert('change to hide');
        	$("#users_header").removeClass('header_expanded');
        	$("#users_header").addClass('header_collapsed');
        	$("#users_body").hide();
    	});

    	$("#guests_header").toggle(function(e){
        	$("#guests_header").removeClass('header_collapsed');
       	 $("#guests_header").addClass('header_expanded');
        	$("#guests_body").show();
    	}, function(e) {
        	$("#guests_header").removeClass('header_expanded');
        	$("#guests_header").addClass('header_collapsed');
        	$("#guests_body").hide();
    	});

    	$("#bots_header").toggle(function(e){
       	 $("#bots_header").removeClass('header_collapsed');
        	$("#bots_header").addClass('header_expanded');
        	$("#bots_body").show();
    	}, function(e) {
        	$("#bots_header").removeClass('header_expanded');
        	$("#bots_header").addClass('header_collapsed');
       	 $("#bots_body").hide();
    	});
	}
};
})(jQuery);

