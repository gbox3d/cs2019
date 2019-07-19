const http = require('http');
const url = require('url');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {

  console.log(req.url);

  let result = url.parse(req.url,true);



  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/html');
  res.write('<h2>' + result.pathname + '</h2>')
  res.end('<h1>Hello World</h1>');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});