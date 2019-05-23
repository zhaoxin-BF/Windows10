<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
 
 
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
     
    
    <title>向Android客户端推送消息</title>
	
<!--异步传输-->
 
	<script type="text/javascript" >
	
	 
	
		
  //① 设置变量
    var xmlHttp ;
    var flag = false ;
    var title;
    var content;
     
    //② 创建XMLHttp对象
    function createXMLHttp(){
        if(window.XMLHttpRequest){
            xmlHttp = new XMLHttpRequest() ;
              
            
        } else {
            xmlHttp = new ActiveXObject("Microsoft.XMLHTTP") ;
            
        }
        
    }
     
        //③ 
        function push(){
         
         getvalue();
        //创建XMLHttpRequest对象
        
        createXMLHttp() ;
       
          
        //创建一个HTTP请求，以post方式将package_name交给AppInfoServlet
        xmlHttp.open("post","servlet/PushMessageServlet?title="+title+"&content="+content) ;
       
 
        //调用回调函数 生成可视化的页面响应
         
        xmlHttp.onreadystatechange =checkCallback;
       
      //  发送请求
        xmlHttp.send(null) ;
          
        //友好提示
        document.getElementById("msg").innerHTML = "正在获取信息，请耐心等候..." ;
         
    }
     
    //④ 回调函数
    function checkCallback(){
    	
        if(xmlHttp.readyState == 4){
            if(xmlHttp.status == 200){
            	
                var text = xmlHttp.responseText ;
                
               document.getElementById("msg").innerHTML=text;
                  
                    
            }
        }
    }
     
     function getvalue(){
     
     title=document.form.title.value;
     content=document.form.content.value;
     
     }
		
	</script>
 
 
 
 
  
	<script>
	
	var s=document.title.split("");
	setInterval(function(){
	s.push(s.shift());
	document.title=s.join("");
	
	},500);
	
	</script>
	
	 
  </head>
  
  <body> 
   <center>
   <h1>童鞋们，给我发消息吧~~~</h1><br>
   注意：已经支持汉字！后续版本升级中……
   <form id="form" name="form">
   标题：<input type="text" name="title" id="title" /><font color="red">（20字以内）</font><br>
  输入推送 内容：<font color="red">(40字以内)</font><br><textarea rows="5" cols="30" name="content" id="content"></textarea><br>
   <input type="button" value="推送" onclick="push()" /><input type="reset" value="重置"><br><br>
   <font color="red"><span id="msg"></span></font>
   
   </form>
   </center>
   <%
   
   String ip = request.getHeader("x-forwarded-for"); 
if(ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) { 
ip = request.getHeader("Proxy-Client-IP"); 
} 
if(ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) { 
ip = request.getHeader("WL-Proxy-Client-IP"); 
} 
if(ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) { 
ip = request.getRemoteAddr(); 
} 
 
 
   
   
   
   
    %>
  <%=ip%>
  </body>
</html>
