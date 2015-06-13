title: Hexo Startup
---
hexo 博客框架 初接触

#一 概念：what is hexo
Hexo is a fast, simple and powerful blog framework. You write posts in Markdown (or other languages) and Hexo generates static files with a beautiful theme in seconds.
![](http://ts3.mm.bing.net/th?id=JN.1qAGoJTu6pMLggHu8ygYnw&pid=15.1)
#二 安装+实践
##2.1 环境部署
windows platform 上，请使用管理员权限安装
参考 知乎某牛的guide
[click me](http://www.zhihu.com/question/20962496)


##2.2 安装精要
node.js --> hexo install --> hexo init 目标文件夹 -->hexo new 标题
--> hexo gernerate --> hexo server
到此，你就可以本地预览你的博客内容了

详细见链接，仅把难点放在下面
##2.3 问题
本地预览出现如下error
```
<%- partial('_partial/head') %>              
<%- partial('_partial/header') %>              
<%- body %>              
<% if (theme.sidebar && theme.sidebar !== 'bottom'){ %> <%- partial('_partial/sidebar') %> <% } %>               
<%- partial('_partial/footer') %>             
<%- partial('_partial/mobile-nav') %>
<%- partial('_partial/after-footer') %>
```
##2.4 解决方案
```
npm install hexo-renderer-ejs --save

npm install hexo-renderer-stylus --save

npm install hexo-renderer-marked --save
```

#三 思考
hexo作为静态博客框架，易用性不错。
以前听说过wordpress, 但是感觉研究时间成本过高，就放弃了。
而Hexo上手的实践过程，不过1-2小时，推荐爱好者使用。

###弊端
从 阮一峰博客上看到，
```
　　* 有一定技术门槛，你必须要懂一点git和网页开发。
　　* 它生成的是静态网页，添加动态功能必须使用外部服务，比如评论功能就只能用disqus。
　　* 它不适合大型网站，因为没有用到数据库，每运行一次都必须遍历全部的文本文件，网站越大，生成时间越长。
```
其中，就是可扩展性较差，不过对于我等小众博客爱好者，我认为够了。


#参考
[error above solution](http://blog.csdn.net/tstbdt/article/details/44042693)