import { Grid } from '@mui/material';
import React, { useEffect } from 'react';
import { Api } from '../services/api.service';
import { LineChart, Line, XAxis, CartesianGrid, YAxis, Tooltip } from 'recharts';

function GraphVitAcc() {
	const [vitesse, setVitesse] = React.useState([]);
	//const [acceleration, setAcceleration] = React.setState([]);


	useEffect(() => {
		var data = [];
		for(var i = 0; i < 10000; i++) {
			data.push({ms: i, v: i*10});
		}

		setVitesse(data);

		Api().get("hello").then((data) => {
			console.log(data);
		})
	}, [])

	return (
		<React.Fragment>
			<Grid
				container
				spacing={0}
				direction="column"
				alignItems="center"
				justifyContent="center"
			>
				<Grid item xs={3}>
					<LineChart width={500} height={300} data={vitesse}>
						<XAxis dataKey="ms"/>
						<YAxis/>
						<Tooltip />
						<CartesianGrid stroke="#eee" strokeDasharray="5 5"/>
						<Line type="monotone" dataKey="v" stroke="#8884d8" />
					</LineChart>
				</Grid>
			</Grid>
		</React.Fragment>
	);
}

export default GraphVitAcc;
