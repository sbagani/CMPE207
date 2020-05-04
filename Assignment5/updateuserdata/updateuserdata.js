
`use strict`

const AWS = require('aws-sdk');

AWS.config.update({region :"us-east-1"})

exports.handler = function(id,firstname,lastname)
{
  
   const db = new AWS.DynamoDB.DocumentClient({apiVersion: "2012-10-08"});
   
  
   const params ={
       TableName: "Users",
       Key :{
           id:{
               S:"67890"
           },
           UpdateExpression: "set firstname = :f",
		    ExpressionAttributeValues:{
		        ":f":"fullname"
		    },
		    ReturnValues:"UPDATED_NEW"
       }
   }
   db.update(params,(err,data) => {
       if(err){
           console.log(err);
       }
       console.log(data);
   })
}