// Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\">");
           
            client.println("</head>");
            
   
           
            client.println("<body class=\"text-center bg-dark text-white\"><h1>Dashboard</h1>");

            client.println("<div class=\"container border border-success\">");

            client.println("<div class=\"row\">");
            
            // D1
            client.println("<div class=\"border col-lg-6 col-md-6 col-sm-12 pt-4\">");
            client.println("<h5>Device 1</h5>");
            client.println("<p>State : " + output1State + "</p>");
            // If the output1State is off, it displays the ON button       
            if (output1State=="off") {
              client.println("<p><a href=\"/D1/on\"><button class=\"btn btn-lg btn-success\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/D1/off\"><button class=\"btn btn-lg btn-danger\">OFF</button></a></p>");
            } 
            client.println("<p>Power consumption  20 watt</p>");
            client.println("<p>Active Time = "+String(time1)+" Second</p>");
            client.print("<p>Energy Use = ");
            client.print(double(((double(time1)/3600)* 50)/1000),4);
            client.println("  Unit</p>");
            client.println("</div>");

            
               
            //D2
            client.println("<div class=\"border col-lg-6 col-md-6 col-sm-12 pt-4\">");
            client.println("<h5>Device 2</h5>");
            client.println("<p>State : " + output2State + "</p>");
            // If the output4State is off, it displays the ON button       
            if (output2State=="off") {
              client.println("<p><a href=\"/D2/on\"><button class=\"btn btn-lg btn-success\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/D2/off\"><button class=\"btn btn-lg btn-danger\">OFF</button></a></p>");
            }
            client.println("<p>Power consumption  30 watt</p>");
            client.println("<p>Active Time = "+String(time2)+" Second</p>");
            client.print("<p>Energy Use = ");
            client.print(double(((double(time2)/3600)* 50)/1000),4);
            client.println("  Unit</p>");
            client.println("</div>");





            //D3
  
            client.println("<div class=\"border col-lg-6 col-md-6 col-sm-12 pt-4\">");
            client.println("<h5>Device 3</h5>");
            client.println("<p>State : " + output3State + "</p>"); 
            
            // If the output4State is off, it displays the ON button       
            if (output3State=="off") {
              client.println("<p><a href=\"/D3/on\"><button class=\"btn btn-lg btn-success\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/D3/off\"><button class=\"btn btn-lg btn-danger\">OFF</button></a></p>");
            }
            client.println("<p>Power consumption  40 watt</p>");
            client.println("<p>Active Time = "+String(time3)+" Second</p>");
            client.print("<p>Energy Use = ");
            client.print(double(((double(time3)/3600)* 50)/1000),4);
            client.println("  Unit</p>");

            client.println("</div>");



            //D4
            client.println("<div class=\"border col-lg-6 col-md-6 col-sm-12 pt-4\">");

            client.println("<h5>Device 4</h5>");
            client.println("<p>State : " + output4State + "</p>");
            // If the output4State is off, it displays the ON button       
            if (output4State=="off") {
              client.println("<p><a href=\"/D4/on\"><button class=\"btn btn-lg btn-success\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/D4/off\"><button class=\"btn btn-lg btn-danger\">OFF</button></a></p>");
            }
            client.println("<p>Power consumption  50 watt</p>");
            client.println("<p>Active Time = "+String(time4)+" Second</p>");
            
          client.print("<p>Energy Use = ");
          client.print(double(((double(time4)/3600)* 50)/1000),4);
          client.println("  Unit</p>");

          
            client.println("</div>");


            client.println("</div>"); ///row
            client.println("</div>"); // container


            client.println("<script language=\"javascript\">");
            client.println("setInterval(function(){window.location.reload(1);}, 5000);</script>");

  
            
            
            client.println("</body></html>");
