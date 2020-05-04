'use strict';
const AWS = require('aws-sdk'); // define the syntax what to call and how

exports.handler = async (event, context) => {
  const documentClient = new AWS.DynamoDB.DocumentClient();

  let responseBody = "";
  let statusCode = 0;


//Key to delete
  const params = {
    TableName: "Users",
    Key: {
      id : "12345"
    }
  };

//globally defined promise function

  try {
    const data = await documentClient.delete(params).promise();
    responseBody = JSON.stringify(data);
    statusCode = 204;
  } catch(err) {
    responseBody = `Unable to delete item: ${err}`;
    statusCode = 403;
  }
  const response = {
    statusCode: statusCode,
    headers: {
      "Content-Type": "application/json"
    },
    body: responseBody
  };

  return response;
};